import stock as st 
import LSTM_model as lstm
import transformer_model as tm

apple = 'AAPL'
google = 'GOOG'
nvidia = 'NVDA'

#apple_stock, apple_train, apple_test, apple_scaler, apple_currency = st.prepare_data(apple)
google_stock, google_train, google_test, google_scaler, google_currency = st.prepare_data(google)
#nvidia_stock, nvidia_train, nvidia_test, nvidia_scaler, nvidia_currency = st.prepare_data(nvidia)

#lstm.lstm_model(apple_stock, "Apple", apple_train, apple_test, apple_scaler, apple_currency)
#lstm.lstm_model(google_stock, "Google", google_train, google_test, google_scaler, google_currency)
#lstm.lstm_model(nvidia_stock, "Nvidia", nvidia_train, nvidia_test, nvidia_scaler, nvidia_currency)


#tm.tranformer_model(apple_stock, "Apple", apple_train, apple_test, apple_scaler, apple_currency)
tm.tranformer_model(google_stock, "Google", google_train, google_test, google_scaler, google_currency)
#tm.tranformer_model(nvidia_stock, "Nvidia", nvidia_train, nvidia_test, nvidia_scaler, nvidia_currency)