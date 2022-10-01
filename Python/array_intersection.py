__author__ = "Abhinay Yadav"

"""
Find the Union and Intersection of the two sorted arrays.
"""

def arr_inter(arr1, arr2):
    """Function to find intersection and union of two lists

    Args:
        arr1 ([type]): [description]
        arr2 ([type]): [description]

    Returns:
        List: List of union and Intersection
    """

    if len(arr1) > len(arr2):
        arr1, arr2 =arr2 , arr1
        
    size1 = len(arr1)
    size2 = len(arr2)
    left = 0
    right = 0

    inter =[]
    unionl =[]
    while left < size1 and right < size2:

        if arr1[left] == arr2[right]:
            if arr1[left] not in inter:
                inter.append(arr1[left])
            if arr1[left] not in unionl:
                unionl.append(arr1[left])
            left = left + 1
            right = right + 1
        elif arr1[left] < arr2[right]:
            if arr1[left] not in unionl:
                unionl.append(arr1[left])
            if arr1[left] not in unionl:
                unionl.append(arr2[right])
            left = left +1
        
        elif arr1[left] > arr2[right]:
            if arr1[left] not in unionl:
                unionl.append(arr1[left])
            if arr1[left] not in unionl:
                unionl.append(arr2[right])
            right = right +1
        
    while right < size2:
        if arr2[right] not in unionl:
            unionl.append(arr2[right])
        right = right +1
    
    return (inter, unionl)


assert arr_inter([1,2,3,4,5], [1,2,3,4,5,6]) == ([1,2,3,4,5], [1,2,3,4,5,6])