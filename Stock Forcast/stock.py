import yfinance as yf
from sklearn.preprocessing import MinMaxScaler
from datetime import date

current_date = date.today().isoformat()

# get stock data from Yahoo Finance
def get_stock_data(stock):
    currency = yf.Ticker(stock).info['currency']
    
    stock = yf.download(stock, start='2010-01-01', end=current_date)
    stock = stock[['Close']]
    
    return stock, currency

# perpare data for training, testing
def prepare_data(stock):
    stock_data, stock_currency = get_stock_data(stock)
    
    scaler = MinMaxScaler(feature_range=(0, 1))
    scaler_data = scaler.fit_transform(stock_data.values.reshape(-1, 1))
    
    train_size = int(len(scaler_data) * 0.8)
    train_data = scaler_data[:train_size]
    test_data = scaler_data[train_size:]
    
    return stock_data, train_data, test_data, scaler, stock_currency