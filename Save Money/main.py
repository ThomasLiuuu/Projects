from flask import Flask, request, jsonify
import web_search as web
import db_search as db

app = Flask(__name__)

# search for coffee price in database
@app.route('/search/coffee', methods = ['GET'])
def search_coffee_price():
    coffee_name = request.args.get('coffee_name')
    brand = request.args.get('brand')
    size = request.args.get('size')
    
    price = db.get_coffee_price(coffee_name, brand, size)
    
    if price is None:
        return jsonify({"message": "Price not found, please provide the coffee price"}), 404

    return jsonify({"price": price}), 200

# save coffee price to database
@app.route('/save/coffee', methods = ['POST'])
def save_coffee_price():
    coffee_name = request.json.get('coffee_name')
    brand = request.json.get('brand')
    size = request.json.get('size')
    price = request.json.get('price')
    
    if not all([coffee_name, brand, size, price]):
        return jsonify({"error": "Please provide all the required fields"}), 400
    
    db.save_coffee_price(coffee_name, brand, size, price)
    return jsonify({"message": "Price saved successfully"})

# search for interest rate
@app.route('/search/interest_rate', methods = ['GET'])
def search_interest_rate():
    date, interest_rate = web.get_interest_rate()
    
    if interest_rate is None:
        return jsonify({"error": "Failed to fetch interest rate"}), 500

    return jsonify({"date": date, "interest_rate": interest_rate}), 200

# calculate future value of coffee expense
@app.route('/calculate/future_value', methods = ['POST'])
def calculate_future_value():
    data = request.json
    price = float(data.get('price'))
    frequency = int(data.get('frequency'))
    length = int(data.get('length'))
    
    interest_rate = web.get_interest_rate()[1]
    
    present_value = price * frequency * 52
    future_value = present_value * (1 + interest_rate) ** length
    
    return jsonify({
        "present_value": present_value,
        "future_value": future_value
    })

if __name__ == '__main__':
    app.run(debug=True)