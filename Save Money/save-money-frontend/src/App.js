import React, { useState } from 'react';
import axios from 'axios';
import './App.css';

function App() {
    const [coffeeName, setCoffeeName] = useState('');
    const [brand, setBrand] = useState('');
    const [size, setSize] = useState('');
    const [price, setPrice] = useState('');
    const [frequency, setFrequency] = useState('');
    const [length, setLength] = useState('');
    const [futureValue, setFutureValue] = useState('');
    const [message, setMessage] = useState('');

    const backendUrl = "http://127.0.0.1:5000"

    // get coffee price
    const searchCoffee = async () => {
        try {
            const response = await axios.get(
                `${backendUrl}/search/coffee`, {
                params: {
                    coffee_name: coffeeName,
                    brand: brand,
                    size: size 
                },
            });
            setPrice(response.data.price);
            setMessage("");
        } catch (error) {
            console.log("Error searching for coffee price", error);
            setMessage(error.response?.data?.message || "An error occurred");
            setPrice("");
        }
    };

    // save coffee price
    const saveCoffee = async () => {
        try {
            const response = await axios.post(
                `${backendUrl}/save/coffee`, {
                    coffee_name: coffeeName,
                    brand: brand,
                    size: size,
                    price: price
            });
            setMessage(response.data.message);
        } catch (error) {
            console.log("Error saving coffee price", error);
            setMessage(error.response?.data?.error || "An error occurred");
        }
    };

    // calculate future value
    const calculateFutureValue = async () => {
        try {
            const response = await axios.get(
                `${backendUrl}/calculate/future_value`, {
                    price: price, 
                    frequency: frequency,
                    length: length 
            });
            setFutureValue(response.data.future_value);
        } catch (error) {
            setMessage("Error calculating future value");
        }
    }; 

    return (
        <div class="App">
            <h1>Save Money on Coffee</h1>

            <label>Coffee Name: </label>
            <input type="text" value={coffeeName} onChange={(e) => setCoffeeName(e.target.value)} />

            <label>Brand: </label>
            <input type="text" value={brand} onChange={(e) => setBrand(e.target.value)} />

            <label>Size: </label>
            <input type="text" value={size} onChange={(e) => setSize(e.target.value)} />

            <button onClick={searchCoffee}>Search Price</button>
            <p>{message}</p>
            {price && <p>Price: ${price}</p>}

            {message && (
                <>
                    <label>Enter Price: </label>
                    <input value={price} onChange={(e) => setPrice(e.target.value)} />
                    <button onClick={saveCoffee}>Save Price</button>
                </>
            )}

            <h2>Future Value Calculator</h2>
            <label>How often per week?</label>
            <input type="number" value={frequency} onChange={(e) => setFrequency(e.target.value)} />

            <label>Years of Drinking Coffee: </label>
            <input type="number" value={length} onChange={(e) => setLength(e.target.value)} />

            <button onClick={calculateFutureValue}>Calculate Future Value</button>
            {futureValue && <p>Future Value: ${futureValue}</p>}
        </div>
    );
}

export default App;
