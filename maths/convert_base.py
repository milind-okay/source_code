convert_string = "0123456789ABCDEF"
def to_str(n, base):
 
 if n < base:
     return convert_string[n]
 else:
     return to_str(n / base, base) + convert_string[n % base]
print(to_str(15, 16))
print(to_str(15, 2))
print(to_str(15, 10))
print(to_str(151, 16))
