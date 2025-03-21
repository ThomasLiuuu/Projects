import stock as st 
import LSTM_model as lstm
import transformer_model as tm

stocks = {
    'AAPL': 'Apple',
    'GOOG': 'Google',
    'NVDA': 'Nvidia',
    'SMCI': 'Super Micro Computer Inc'
}

for ticker, company in stocks.items():
    print(f"Fetching data for {company} ({ticker})...")
    
    stock_data, x_train, y_train, x_test, y_test, scaler, currency = st.prepare_data(ticker)

    print(f"Training LSTM model for {company}...")
    lstm.lstm_model(stock_data, company, x_train, y_train, x_test, y_test, scaler, currency)