def solution(data, n):
    new_data = []
    occurrences = {}

    for i in data:
        if i in occurrences.keys():
            occurrences[i] += 1
        else:
            occurrences[i] = 1

    for i in data:
        if occurrences[i] <= n:
            new_data.append(i)

    # print(data)
    print(occurrences)
    return new_data


print(solution([1, 2, 2, 3, 3, 3, 4, 5, 5], 1))
