def remove_duplicates(input_list):
    unique_list = []
    for item in input_list:
        if item not in unique_list:
            unique_list.append(item)
    return unique_list
num_elements = int(input())
input_list = []
for _ in range(num_elements):
    element = int(input())
    input_list.append(element)
result = remove_duplicates(input_list)
print(result)


# def sum_ascii_values(s1):
#     total_sum = 0
#     for char in s1:
#         total_sum += ord(char)
#     return total_sum
# input_str = input()
# result = sum_ascii_values(input_str)
# print(result)

