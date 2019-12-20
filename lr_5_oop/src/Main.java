import java.io.*;
import java.io.Serializable;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


class TestFrame extends JFrame {
    public TestFrame() {
        super("Test frame");
        createGUI();
    }
    public void createGUI() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel();
        panel.setLayout(null);
        JButton button1 = new JButton("Button 1");
        button1.setBounds(5, 5, 85, 30);
        panel.add(button1);
        JButton button2 = new JButton("Button 2");
        button2.setBounds(95, 40, 85, 30);
        panel.add(button2);
        JButton button3 = new JButton("Button 3");
        button3.setBounds(185, 75, 85, 30);
        panel.add(button3);
        getContentPane().add(panel);
        setPreferredSize(new Dimension(285, 145));
    }
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                JFrame.setDefaultLookAndFeelDecorated(true);
                TestFrame frame = new TestFrame();
                frame.pack();
                frame.setLocationRelativeTo(null);
                frame.setVisible(true);
            }
        });
    }
}


class parent implements Serializable {
    int parentVersion = 10;
}

class contain implements Serializable{
    int containVersion = 11;
}
class SerialTest extends parent implements Serializable {
    int version = 66;
    contain con = new contain();

    public int getVersion() {
        return version;
    }
    public static void main(String args[]) throws IOException {
        FileOutputStream fos = new FileOutputStream("temp.out");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        SerialTest st = new SerialTest();
        oos.writeObject(st);
        oos.flush();
        oos.close();
    }
}