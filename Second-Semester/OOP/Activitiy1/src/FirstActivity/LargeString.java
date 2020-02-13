package FirstActivity;
import java.io.IOException;
import java.util.Scanner;

public class LargeString {
		public static void main(String[] arg) 
		{
			Scanner input = new Scanner(System.in);
			int number = 0;
			String originalString = "";
			String largerString = "";
			System.out.println("Input a string.");
			originalString = input.nextLine();
			System.out.println("Input how many copies of this string.");
			number = input.nextInt();
			while(number < 0)					// Validation in case input ni user ay less than 0
			{
				System.out.println("Number of copies cannot be a negative number. Please try again.");
				number = input.nextInt();
			}
			for(int a = 0; a < number ; a++)
				largerString+=originalString; // Concatenation(pagkakabit ng string sa isa't isa)
			
			System.out.printf("Original String: %s \nLarger String: %s", originalString, largerString);
			System.exit(0);
			
		}
}
