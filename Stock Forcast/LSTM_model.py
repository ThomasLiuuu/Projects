import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tensorflow as tf 
from sklearn.preprocessing import MinMaxScaler
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

def lstm_model(stock_data, company, train_data, test_data, scaler, currency): 
    def create_sequence(data, seq_length = 60):
        x, y = [], []
        for i in range(len(data) - seq_length - 1):
            x.append(data[i:(i + seq_length)])
            y.append(data[i + seq_length])
        return np.array(x), np.array(y)
    
    x_train, y_train = create_sequence(train_data)
    x_test, y_test = create_sequence(test_data)
    
    x_train = x_train.reshape(x_train.shape[0], x_train.shape[1], 1)
    x_test = x_test.reshape(x_test.shape[0], x_test.shape[1], 1)
    
    model = tf.keras.models.Sequential([
        tf.keras.layers.LSTM(50, return_sequences=True, input_shape=(x_train.shape[1], 1)),
        tf.keras.layers.LSTM(50, return_sequences=False),
        tf.keras.layers.Dense(25),
        tf.keras.layers.Dense(1)
    ])
    
    model.compile(optimizer='adam', loss='mean_squared_error')
    model.summary()
    
    history = model.fit(x_train, y_train, batch_size=1, epochs=1)
    
    prediction = model.predict(x_test)
    prediction = scaler.inverse_transform(prediction)
    y_test_scaled = scaler.inverse_transform(y_test.reshape(-1, 1))
    
    plt.figure(figsize=(10, 6))
    plt.plot(stock_data.index[-len(y_test):], y_test_scaled, label='True Price', color='blue')
    plt.plot(stock_data.index[-len(prediction):], prediction, label='Predicted Price', color='red')
    plt.title(f'{company} Stock Price Prediction')
    plt.xlabel('Time')
    plt.ylabel(f'Price ({currency})')
    plt.legend()
    plt.grid()
    plt.show()
    
    mae = mean_absolute_error(y_test_scaled, prediction)
    rmse = np.sqrt(mean_squared_error(y_test_scaled, prediction))
    r2 = r2_score(y_test_scaled, prediction)
    
    print(f'Mean Absolute Error: {mae}')
    print(f'Root Mean Squared Error: {rmse}')
    print(f'R2 Score: {r2}')