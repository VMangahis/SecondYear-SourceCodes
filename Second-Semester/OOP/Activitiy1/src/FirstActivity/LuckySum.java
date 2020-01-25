package FirstActivity;
import java.util.Scanner;

public class LuckySum {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int[] numbers = new int[3];
		int sum = 0;
		for(int a = 0; a < 3 ; a++) 
		{
			System.out.println("Enter a number.");
			numbers[a] = input.nextInt();
		}
		
		for(int x : numbers)
		{
			if(x == 13)
				break;
			
			sum+=x;
		}
		
		System.out.println("Final sum: " + sum);
		System.exit(0);

	}

}
