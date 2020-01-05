import javax.swing.JOptionPane;

public class Temperature {

	public static void main(String[] args) {
		String f;
		Float fNumber;
		Float celsius;
		f = JOptionPane.showInputDialog(null, "Input temperature in Fahrenheit.", 0.0);  // String lagi ang nagiging dating ng iniinput natin sa GUI
		if(f == null)											// In case walang iinput si user exit na
		{
			System.exit(0);
		}
		fNumber = Float.parseFloat(f);							// Yung string na number na ininput ni user ay coconvert natin sa float
		while(f == null || fNumber == null)						//Validation lang in case letter iinput ni user
		{
			JOptionPane.showInputDialog(null, "Error Input!\nInput temperature in Fahrenheit.");    
		}
		celsius = (5*(fNumber-32))/9;							//Conversion
		JOptionPane.showMessageDialog(null, "Fahrenheit :" + fNumber + "\nCelsius :" + celsius); // Output

	}

}
