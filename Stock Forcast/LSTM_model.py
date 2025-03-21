import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

def lstm_model(stock_data, company, x_train, y_train, x_test, y_test, scaler, currency, epochs=10, batch_size=32):
    seq_length = x_train.shape[1]

    model = tf.keras.models.Sequential([
        tf.keras.layers.LSTM(50, return_sequences=True, input_shape=(seq_length, 1)),
        tf.keras.layers.LSTM(50, return_sequences=False),
        tf.keras.layers.Dense(25),
        tf.keras.layers.Dense(1)
    ])

    model.compile(optimizer='adam', loss='mean_squared_error')
    model.summary()

    # train model
    model.fit(x_train, y_train, batch_size=batch_size, epochs=epochs, verbose=1)

    # predict and inverse transform
    predictions = model.predict(x_test)
    predictions = scaler.inverse_transform(predictions)
    y_test_scaled = scaler.inverse_transform(y_test.reshape(-1, 1))

    # plot results
    plt.figure(figsize=(10, 6))
    plt.plot(stock_data.index[-len(y_test):], y_test_scaled, label='True Price', color='blue')
    plt.plot(stock_data.index[-len(predictions):], predictions, label='Predicted Price', color='red')
    plt.title(f'{company} Stock Price Prediction')
    plt.xlabel('Time')
    plt.ylabel(f'Price ({currency})')
    plt.legend()
    plt.grid()
    plt.show()

    # performance metrics
    mae = mean_absolute_error(y_test_scaled, predictions)
    rmse = np.sqrt(mean_squared_error(y_test_scaled, predictions))
    r2 = r2_score(y_test_scaled, predictions)

    print(f'{company} - Mean Absolute Error: {mae}')
    print(f'{company} - Root Mean Squared Error: {rmse}')
    print(f'{company} - R2 Score: {r2}')

    return model