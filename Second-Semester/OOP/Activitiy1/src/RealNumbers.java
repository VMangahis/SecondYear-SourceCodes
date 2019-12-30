import java.util.Scanner;

public class RealNumbers {

	public static void main(String[] args) {
		
		Scanner cont = new Scanner(System.in);
		double realNum = 0.1;
		int integer = 0;
		double sum = 0.0;
		System.out.println("Issue with real numbers. Press enter to proceed to the next calculation.");
		for(int a = 0; a < 10 ; a++)
		{
			System.out.println("(" + sum + " + " + realNum + ")" + " = " + (sum+realNum));
			if(a == 2 || a == 7 || a == 8 || a == 9)
			{
				System.out.println("Infinite Decimal Places!");
			}
			cont.nextLine();
			sum+=realNum;
			
		}	
		System.out.println("Program End.");
	}

}
