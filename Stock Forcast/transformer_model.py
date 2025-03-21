import torch
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt

def tranformer_model(stock_data, company, train_data, test_data, scaler, currency):
    def create_sequence(data, seq_length = 60):
        x, y = [], []
        for i in range(len(data) - seq_length - 1):
            x.append(data[i:(i + seq_length)])
            y.append(data[i + seq_length])
        return np.array(x), np.array(y)
    
    class transformer(nn.Module):
        def __init__(self, input_dim=1, num_heads=1, num_layers=2):
            super(transformer, self).__init__()
            self.encoder_layer = nn.TransformerEncoderLayer(
                d_model=input_dim, nhead=num_heads, batch_first=True
            )
            self.transformer_encoder = nn.TransformerEncoder(
                self.encoder_layer, num_layers=num_layers
            )
            self.fc = nn.Linear(input_dim, 1)
            
        def forward(self, x):
            x = self.transformer_encoder(x)
            x = self.fc(x[:, -1, :])  
            return x
        
    x_train, y_train = create_sequence(train_data)
    x_test, y_test = create_sequence(test_data)
    
    x_train = torch.tensor(x_train, dtype=torch.float32).reshape(-1, 60, 1)
    y_train = torch.tensor(y_train, dtype=torch.float32).reshape(-1, 1)
    x_test = torch.tensor(x_test, dtype=torch.float32).reshape(-1, 60, 1)
    y_test = torch.tensor(y_test, dtype=torch.float32).reshape(-1, 1)
    
    model = transformer()
    criterion = nn.MSELoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.001)
    
    for epoch in range(20):
        optimizer.zero_grad()
        outputs = model(x_train)
        loss = criterion(outputs, y_train)
        loss.backward()
        optimizer.step()
        print(f'Epoch {epoch + 1}, Loss: {loss.item()}')
        
    model.eval()
    with torch.no_grad():
        y_pred = model(x_test).numpy()
    
    y_pred_scaled = scaler.inverse_transform(y_pred)
    y_test_scaled = scaler.inverse_transform(y_test.numpy())
    
    plt.figure(figsize=(10, 6))
    plt.plot(stock_data.index[-len(y_test):], y_test_scaled, label='True Price', color='blue')
    plt.plot(stock_data.index[-len(y_pred):], y_pred_scaled, label='Predicted Price', color='red')
    plt.title(f'{company} Stock Price Prediction')
    plt.xlabel('Time')
    plt.ylabel(f'Price ({currency})')
    plt.legend()
    plt.grid()
    
    
    
    