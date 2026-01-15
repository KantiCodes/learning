import random



def execPivot(l: list, start, end):
    """Both ends inclusive"""
    i=start-1
    j=start
    # pivot_id = random.randint(0, len(l)-1)
    pivot_id = end
    pivot = l[pivot_id]
    print(f"\tFor l: {l}, pivot is: {pivot}")

    for j in range(start, end):
        if l[j] < pivot:
            i+=1
            l[i], l[j] = l[j], l[i]
    
    # all the elements on the left of i and including i are smaller than pivot
    # that means that the i+1 element is bigger than pivot
    # hence the place of the pivot is on the i+1 index 1 3 2 8 (if pivot is 4) then i will be 2
    # and the i+1 -> 8 will be the out of place
    l[i+1], l[pivot_id] = pivot, l[i+1]
    print (f"\tl after: {l}")
    return i+1

def _qsort(l: list, start, end):
    if start < end:
        pivot_id = execPivot(l, 0, len(l)-1)

        execPivot(l, 0 , pivot_id-1)
        execPivot(l, pivot_id+1, len(l)-1)


def qsort(l):
    _qsort(l,0, len(l)-1)

v = [10, 80, 30, 90, 40]

qsort(v)

print(f"After v: {v}")