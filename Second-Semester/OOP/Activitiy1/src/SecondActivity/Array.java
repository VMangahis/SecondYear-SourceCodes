package SecondActivity;

import java.util.Scanner;

public class Array {

	public static void main(String[] args) {
		
		
		//Initialize
		int numItems = 0;
		int items[];
		Scanner input = new Scanner(System.in);
		
		
		System.out.println("Input number of items");
		numItems = input.nextInt();
		items = new int[numItems];
		
		
		
		System.out.println("Enter the value of each items:");
		for(int in = 0; in < numItems ; in++)
		{
			System.out.println("Item " + (in+1));
			items[in] = input.nextInt();
		}
		
		for(int num = 0; num < numItems ; num++)
		{
			System.out.print(num + ":  ");
			for(int stars = 0; stars < items[num] ; stars++ )
			{
				System.out.print("*");
			}
			System.out.println("(" + items[num] + ")");
		}
		
		
		

	}

}
