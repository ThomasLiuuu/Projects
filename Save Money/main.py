import web_search as web
import db_search as db

'''
# search for coffee price
brand = input("Enter coffee brand: ")
size = input("Enter coffee size: ")
coffee = input("Enter coffee type: ")

search_target = brand + " " + size + " " + coffee

result = search.google_search(search_target)

if result: 
    title = result["title"]
    price = result["price"]
    link = result["link"]
    
    print("Title: " + title)
    print("Price: " + price)
    print("Link: " + link)'''
    
# search for coffee price
coffee_name = input("Enter coffee name: ")
brand = input("Enter coffee brand: ")
size = input("Enter coffee size: ")

price = db.get_coffee_price(coffee_name, brand, size)

if price is None:
    price = input("Enter the price of the coffee: ")
    db.save_coffee_price(coffee_name, brand, size, price)
    
# ask for frequency of coffee consumption
frequency = input("How many times do you drink this coffee in a week? ")
length = input("How many years do you plan to stick with this coffee and frequency? ")
    
# search for annual interest rate 
interest_rate = web.get_interest_rate()[1]

# calculate the future value of the coffee expense
present_value = float(price) * float(frequency) * 52
future_value = present_value * (1 + interest_rate) ** float(length)

