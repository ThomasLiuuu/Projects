import yfinance as yf
from datetime import date

current_date = date.today().isoformat()

apple = 'AAPL'
google = 'GOOG'
nvidia = 'NVDA'

def apple_stock():
    stock = yf.download(apple, start='2010-01-01', end=current_date)
    return stock[['Close']]

print(apple_stock())