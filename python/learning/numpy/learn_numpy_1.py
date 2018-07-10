'''
    Numpy is a math library for python. It enables us to do computation efficiently, effectively and has amazing capabilities

    In numpy, array, matrix and vector and used interchangeably

    For multi-dimensional arrays, you specify as (num_rows, num_columns)


'''
import numpy as np

# There is no difference between a simple list and numpy array at first glance
# Print of numpy array just shows separated by spaces, instead of commas
def func_01():
    # list
    plist = [1,2,3,4,5,6]
    #numpy array
    nplist = np.array([1,2,3,4,5,6])

    print(plist)
    print (nplist)

# Some simple numpy creation/arrange functions
# arange(from_incl, upto_excl, [step])
# shape() - returns (num_rows,num_cols) - see below for result for nplist and why?
# reshape() - transpose or convert to multidimension matrix
# zeros(tuple(nrows,ncols)) - create a matrix filled with (float) 0
# eye(n) - create an n x n Identity matrix (diagonals filled with 1. )
# random.rand()
def func_02():
    # list
    plist = [1,2,3,4,5,6]
    # numpy array
    nplist = np.array([1,2,3,4,5,6])

    print ('np.arange')
    print(np.arange(10, 20))
    print (np.arange(10, 20, 2))
    print(np.arange(20, 10, -2))

    print('np.shape')
    print (nplist.shape)
    # Instead see what you get when you make some changes
    nplist2 = np.array([[1, 2, 3, 4, 5,6]])
    print(nplist2.shape)
    # This results looks better in the "num_rows,num_cols" format that we expected.
    # Well, that because in the first case, it is really saying 9 rows with 1 column each

    print('np.reshape')
    print(nplist.reshape(1,6))  # See interesting result for this. Makes it == nplist2
    print(nplist2.reshape(6,1))
    print(nplist2.reshape(6,))  # See interesting result for this. Makes it == nplist, but different from previous (5,1)
    print(nplist2.reshape(3, 2))
    print(nplist2.reshape(2, 3))

    print('np.zeros')
    print(  np.zeros(6)  )
    print(  np.zeros(6,)  ) # same as above
    print(  np.zeros((6)) ) # same as above
    print(  np.zeros((6,))) # same as above

    print(  np.zeros((3, 2)) )
    print(  np.zeros((2, 3)) )

    print('np.eye')
    print(np.eye(6))    # Create a 6x6 identity matrix

    print('np.random.rand')
    print(np.random.rand(2, 3))
    print(np.random.rand(2))    # 1 row with two entries
    print(np.random.rand(2,))   # Same as previous
    print(np.random.rand(1,2))  # Not the same as previous two, 1 row with 1 list with 2 elements
    print(np.random.rand(2,1))


# Next, here are some matrix arithmetic operations
def func_03():
    # Two ways to create a list with some known values
    print ("Data")
    nplist1=np.arange(10,16).reshape(2,3)
    nplist2 = np.array(range(20,26)).reshape(3, 2)
    print(nplist1)
    print(nplist2)

    i=0
    i += 1; print (i, nplist1 + nplist1)       # This is adding the values of two "like" matrices
    i += 1; print (i, nplist1 * nplist1)       # This is multiplying the values of two "like" matrices
    i += 1; print (i, np.dot(nplist1, nplist2))    # ( (2x3) * (3x2) = (2x2) ) This is matrix multiplication, diff than the previous one.

    i += 1; print(i, np.sum(nplist1))   # Sum all elements in matrix
    i += 1; print(i, np.sum(nplist1,axis=1))  # Sum all row elements in matrix
    i += 1; print(i, np.sum(nplist1, axis=0))  # Sum all column elements in matrix

    i += 1; print(i, np.diff(nplist1))   # Diff between adjacent elements in matrix. Result for (2x3) is (2x2)
    i += 1; print(i, np.diff(nplist2))  # Diff between adjacent elements in matrix. Result for (3x2) is (3x1)
    i += 1; print(i, np.diff(nplist1,n=2))   # Repeat diff operation 2 times. Result for (2x3) is (2x1)

    i += 1; print(i, nplist1 + 300)   # Add 300 to EACH element of array
    i += 1; print(i, nplist2 + 300)   # Add 300 to EACH element of array
    i += 1; print(i, nplist1 * 300)   # Multiply 300 to EACH element of array


# Some add/delete operations
def func_04():
    print ("Data")
    nplist1=np.arange(10,16)
    nplist2=np.arange(20,26).reshape(3, 2)
    print(nplist1)
    print(nplist2)

    i = 0
    # Append one element
    i += 1; print (i, np.append(nplist1,101))
    i += 1; print (i, np.append(nplist1,[101])) # Same as previous
    print (nplist1) # Capture the return of np.append() if you want to do inplace replacement.
    i += 1; print(i, np.append(nplist2, 101))   # Converts or flattens the multidimen array

    # Append another list
    i += 1; print(i, np.append(nplist2, [101,102]))   # Converts or flattens the multidimen array

    # Create a 2x3 matrix merging two 1x3 matrices (row stack or vstack)
    nplist11 = np.arange(10,13)
    nplist12 = np.arange(20, 23)
    i += 1; print(i, np.vstack(  (nplist11, nplist12)  )    )

    # Create a 3x2 matrix merging two 1x3 matrices (column stack)
    i += 1; print(i, np.column_stack(  (nplist11, nplist12)  )    )

    # Extract some elements or rows
    i += 1; print (i, nplist1[1:3])     # (from_incl, to_excl). Easy to see for a 1 dimen array
    i += 1; print (i, nplist2[1:3])     # In this case, you get "two rows from a 3x2 matrix", not 2 elements


# func_01()
# func_02()
# func_03()
func_04()