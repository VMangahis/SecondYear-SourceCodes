package FirstActivity;
import java.util.Scanner;

public class Bowling {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[][] rolls = new int[10][2];
		int frameScore = 0;
		int defaultPins = 10;
		int totalScore = 0;
		boolean isStrike = false;
		boolean isSpare = false;
		
		
		for(int frame = 0 ; frame < 10 ; frame++)
		{
			System.out.println("Frame: " + (frame+1));
			
			for(int roll = 0; roll < 2; roll++)
			{
				System.out.println("Roll: " + (roll+1));
				System.out.printf("Number of pins knocked down (%d left)", defaultPins);
				System.out.println("Score: " + totalScore);
				rolls[frame][roll] = input.nextInt();
				while(rolls[frame][roll] > defaultPins || rolls[frame][roll] < 0)
				{
					System.out.println("Greater than pins left or negative number is not allowed. Please try again");
					System.out.printf("Number of pins knocked down (%d left)", defaultPins);
					rolls[frame][roll] = input.nextInt();
				}
				
				if(roll == 0 && isSpare)
				{
					totalScore+= (rolls[frame][roll]+ 10); 	 
					isSpare = false;
				}
				
				if(roll == 1 && isStrike)		 
				{
					totalScore += (rolls[frame][roll]+ rolls[frame][roll-1] + 10);  
					isStrike = false;
				}
				
				
				
				defaultPins-=rolls[frame][roll];
				
				if(defaultPins == 0 && roll == 0) 		// Strike
				{
					System.out.println("STRIKE!");
					isStrike = true;
					break;
				}
				else if(defaultPins == 0 && roll == 1) // Spare
				{
					System.out.println("SPARE!");
					isSpare = true;
				}
				else if(roll == 1) 				// Open Frame
				{
					System.out.println("OPEN FRAME!");
					totalScore+=(rolls[frame][roll] + rolls[frame][roll-1]);
				}
			}
			defaultPins = 10;
		}
		System.out.println("Game end!");
		System.out.printf("Your final score is: %d", totalScore);
	}

}
