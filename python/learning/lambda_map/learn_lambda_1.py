'''
The Python lambda statement is an anonymous or unbound function and a pretty limited function at that.
'''
import math


def sqroot(x):
    return math.sqrt(x)

# Think of this as defining a function as f(x) = sqrt(x)
# & then determining f(64) - sqrt(64)
lam_sqroot = lambda x: math.sqrt(x)

print (sqroot(49))
print (lam_sqroot(64))

# Now obviously, assigning a lambda function to a variable is "identical" to a def <func_name>.
# This is not where the "power" of lambda shines. Instead, see its use in conjunction with
# the map() function (see learning/lambda_map for map() details)
numbers = [1,4,9,16]
result = map(lambda x: math.sqrt(x), numbers)
print (list(result))
# Above, the map function applies the lambda function over the iterable numbers

# Or do it all in one step
print(set(map(lambda x: math.sqrt(x), numbers)))
