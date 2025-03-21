import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

class LSTM_Transformer(tf.keras.Model):
    def __init__(self, seq_length):
        super(LSTM_Transformer, self).__init__()

        