
def _insert(l: list, begin: int, end: int):
    print(f"before insert: {l}")
    pivot = l[end]
    i=begin -1
    # For a list of size 5, the end will be 4.
    # Therefore it is not range(begin, end-1) beacause then the range is 1,2,3
    # and we want to compare all elements but pivot that is 1,2,3,4 
    for j in range(begin, end):
        if l[j] < pivot:
            i+=1
            l[i], l[j] = l[j], l[i]

    l[i+1], l[end] = l[end], l[i+1]
    print(f"after insert: {l} with mid: {i}")
    return i+1



def _qsort(l: list, begin: int, end: int):
    print(f"Calling for begin: {begin} and end: {end}")
    input()
    if begin < end:
        mid = _insert(l, begin, end)

        _qsort(l, begin, mid-1)
        _qsort(l, mid+1, end)

def qsort(l: list):
    _qsort(l,0,len(l)-1)

ll = [3,1,2]  
print(f"Before q sort: {ll}")


qsort(ll)
# _insert(l, 0, len(l) -1) 

print(f"After q sort: {ll}")



#               i.      j. 
# [3 1 2]       -1      0
# [3 1 2]       0       1
# 2 1 3
