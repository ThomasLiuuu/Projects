import numpy as np
import yfinance as yf
from sklearn.preprocessing import MinMaxScaler
from datetime import date

current_date = date.today().isoformat()

# get stock data from Yahoo Finance
def get_stock_data(stock):
    currency = yf.Ticker(stock).info.get('currency', 'USD')
    
    stock = yf.download(stock, start='2010-01-01', end=current_date)
    stock = stock[['Close']]
    
    return stock, currency

def create_sequence(data, seq_len):
    x, y = [], []
    
    for i in range(len(data) - seq_len):
        x_i = data[i : i + seq_len]
        y_i = data[i + seq_len]
        
        x.append(x_i)
        y.append(y_i)
        
    x, y = np.array(x), np.array(y)
    
    return x, y

# perpare data for training, testing
def prepare_data(stock):
    stock_data, stock_currency = get_stock_data(stock)
    
    scaler = MinMaxScaler(feature_range=(0, 1))
    scaler_data = scaler.fit_transform(stock_data.values.reshape(-1, 1))
    
    train_size = int(len(scaler_data) * 0.8)
    train_data = scaler_data[:train_size]
    test_data = scaler_data[train_size:]
    
    x_train, y_train = create_sequence(train_data, 10)
    x_test, y_test = create_sequence(test_data, 10)
    
    return stock_data, x_train, y_train, x_test, y_test, scaler, stock_currency