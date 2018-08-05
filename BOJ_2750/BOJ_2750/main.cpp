#include <iostream>
#include <cstdlib>

 
void quickSort(int* arr, int start, int end)
{
    int pivot = arr[end];			
    int left = start;              
    int right = end - 1;          
    int tmp;                      
 
    while (left <= right)       
    {
        while (pivot >= arr[left] && left <= end - 1) 
            left++;
        while (pivot <= arr[right] && right >= start) 
            right--;	
        if (left <= right)  
        {
            tmp = arr[left];        
            arr[left] = arr[right]; 
            arr[right] = tmp;       
			left++;
			right--;
        }
    }
									
	tmp = arr[end];					
	arr[end] = arr[right + 1];		
	arr[right + 1] = tmp;		
 
	if (start <= end)
	{
		quickSort(arr, start, right);		
		quickSort(arr, right + 2, end);		
	}
}
 
int main(void)
{
    int lines;
    scanf("%d", &lines);
    
    int* numbers = new int[lines];
    for (int i = 0; i < lines; i++)
        scanf("%d", &numbers[i]);
    
    int prev;
    quickSort(numbers, 0, lines - 1);

    for (int i = 0; i < lines; i++)
    {
		// 동일한 값이 나올경우에 한 번만 출력
        if (i != 0 && prev == numbers[i])
            continue;
        prev = numbers[i];
        printf("%d\n", numbers[i]);
    }
    
    delete[] numbers;
 
    return 0;
}
