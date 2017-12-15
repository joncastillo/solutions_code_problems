import sys

#perform caterpillar method On^2
def solution(sum, array):

    minimum_sum = -1
    minimum_distance = -1

    for i in range (0, len(array)):
        j = i + 1
        k = len(array) - 1

        while j<k:
            current_sum = array[i] + array[j] + array[k]
            if minimum_sum == -1:
                minimum_sum = current_sum
                minimum_distance = abs(current_sum-sum)
            elif abs(current_sum-sum) < minimum_distance:
                minimum_sum = current_sum
                minimum_distance = abs(current_sum-sum)
            if (current_sum > sum):
                k-=1;
            else:
                j+=1;

    return minimum_sum


def main():
    input_sum = int(input("enter sum:"))
    input_n = int(input("number of elements:"))
    i = 0
    input_array = []
    while (i < input_n):
        input_array.append(int(input("enter element {}: ".format(i))))
        i+=1

    output = solution (input_sum, input_array)
    print("The nearest sum is: {}", output)

if __name__=="__main__":
    main()