def partition(numbers, begin, end):
    r = begin - 1
    for i in range(begin, end):
        if numbers[i] <= numbers[end - 1]:
            r += 1
            numbers[r], numbers[i] = numbers[i], numbers[r]
    return r

def sort(numbers, begin, end):
    if begin < end:
        r = partition(numbers, begin, end)
        sort(numbers, begin, r)
        sort(numbers, r + 1, end)

def search(numbers, begin, end, x):
    if begin == end:
        return begin
    mid = (begin + end) // 2
    if x < numbers[mid]:
        return search(numbers, begin, mid, x)
    elif numbers[mid] < x:
        return search(numbers, mid + 1, end, x)
    else:
        return mid
nums = [32,4,16,2,8,64]
sort(nums, 0, len(nums))
print(nums)
print(search(nums, 0, len(nums), 32))
