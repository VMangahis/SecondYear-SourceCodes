package FirstActivity;
import java.util.Scanner;

public class LargerInteger {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		
		int firstNum = 0;
		int secNum = 0;
		System.out.println("Enter first positive number:");
		firstNum = input.nextInt();
		while(firstNum < 0)
		{
			System.out.println("Input cannot be a negative number. Try Again.");
			System.out.println("Enter first positive number:");
			firstNum = input.nextInt();
		}
		
		System.out.println("Enter second positive number:");
		secNum = input.nextInt();
		while(secNum < 0)
		{
			System.out.println("Input cannot be a negative number. Try Again.");
			System.out.println("Enter second positive number:");
			secNum = input.nextInt();
		}
		if(firstNum > secNum)
		{
			System.out.println("First number is larger.");
			if(firstNum >= 10 && firstNum <= 20)
				System.out.println("Output: " + firstNum);
			
			else 
				System.out.println("Output: " + 0);
			
			System.exit(0);
				
		}
		else {
			System.out.println("Second Number is larger.");
			if(secNum >= 10 && secNum <= 20)
				System.out.println("Output: " + secNum);
			
			else
				System.out.println("Output: " + 0);
			
			System.exit(0);
			
		}
		

	}

}
