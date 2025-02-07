import mysql.connector

# database configuration
db_config = {
    "host": "127.0.0.1",
    "user": "root",
    "password": "lty040609",
    "database": "coffee_db",
    "port": 3306
}

# get coffee price from the database
def get_coffee_price(coffee_name, brand, size):
    connection = mysql.connector.connect(
        host=db_config["host"],
        user=db_config["user"],
        password=db_config["password"],
        database=db_config["database"]
    )
    
    cursor = connection.cursor()
    
    query = """
        SELECT price
        FROM coffee_prices 
        WHERE coffee_name = %s 
        AND brand = %s 
        AND size = %s
    """
    cursor.execute(query, (coffee_name, brand, size))
    result = cursor.fetchone()
    
    connection.close()
    return result

# save coffee price to the database
def save_coffee_price(coffee_name, brand, size, price):
    connection = mysql.connector.connect(
        host=db_config["host"],
        user=db_config["user"],
        password=db_config["password"],
        database=db_config["database"]
    )
    
    cursor = connection.cursor()
    
    query = """
        INSERT INTO coffee_prices (coffee_name, brand, size, price) 
        VALUES (%s, %s, %s, %s)
    """
    cursor.execute(query, (coffee_name, brand, size, price))
    
    connection.commit()
    connection.close()