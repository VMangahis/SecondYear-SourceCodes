import javax.swing.JOptionPane;

public class Temperature {

	public static void main(String[] args) {
		String f;
		Float fNumber;
		Float celsius;
		f = JOptionPane.showInputDialog(null, "Input temperature in Fahrenheit.", 0.0);
		if(f == null)
		{
			System.exit(0);
		}
		fNumber = Float.parseFloat(f);
		while(f == null || fNumber == null)
		{
			JOptionPane.showInputDialog(null, "Error Input!\nInput temperature in Fahrenheit.");
		}
		celsius = (5*(fNumber-32))/9;
		JOptionPane.showMessageDialog(null, "Fahrenheit :" + fNumber + "\nCelsius :" + celsius);

	}

}
