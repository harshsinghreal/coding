def get_user_info(user_input):
    name = user_input.strip().lower() 
    query = f"SELECT * FROM users WHERE name = '{name}'" 
    result = db_execute(query)  
    return result
testing
