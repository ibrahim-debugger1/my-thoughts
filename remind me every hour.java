package helloo;

import java.awt.Dimension;
import java.awt.Font;
import java.time.LocalDateTime;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextPane;


public class Helloo {

   
    public static void main(String[] args) throws InterruptedException {
        JLabel jtp = new JLabel("Hey, get up");
        jtp.setFont(new Font("Serif", Font.PLAIN, 100));
        jtp.setSize(new Dimension(1000, 1000));
        jtp.setPreferredSize(new Dimension(1000, 1000));
        while(true){
            int currmin=LocalDateTime.now().getMinute();
            int hey=((60-currmin)*60)*1000;
            Thread.sleep(hey);
            JOptionPane.showMessageDialog(null,jtp,"get up and move for a five min",JOptionPane.INFORMATION_MESSAGE);
        }
    }
}
