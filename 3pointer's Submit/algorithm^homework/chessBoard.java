import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.print.attribute.standard.JobHoldUntil;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
public class chessBoard extends JFrame {
    private int tr, tc, dr, dc, size;//定义各成员变量
    int tile = 1;
    float red,green,blue;
    JPanel centerPanel;
    JPanel southPanel;
    JButton[][] button;
    JTextField TrText, TcText, DrText, DcText, SizeText;
    JLabel TrLabel, TcLabel, DrLabel, DcLabel, SizeLabel;
    JButton OKButton;
    JButton CancelButton;
    JPanel panel = new JPanel();
    public chessBoard() {
        super();
        setTitle("棋盘覆盖");
        this.setResizable(false);
        centerPanel = new JPanel();
        southPanel = new JPanel();
        OKButton = new JButton("确定或开始");
        OKButton.addActionListener(new OKButtonAction());
        CancelButton = new JButton("取消或清除");
        CancelButton.addActionListener(new OKButtonAction());
        setBounds(30, -10, 900, 600);//设置窗口大小与位置
        TrText = new JTextField("0",2);//定义各组件
        TcText = new JTextField("0",2);
        DrText = new JTextField("0",2);
        DcText = new JTextField("0",2);
        SizeText = new JTextField("4",2);
        TrLabel = new JLabel("起始方格坐标x:   ");
        TcLabel = new JLabel("起始方格坐标y:    ");
        DrLabel = new JLabel("特殊方格坐标x:   ");
        DcLabel = new JLabel("特殊方格坐标y:   ");
        SizeLabel = new JLabel("棋盘规模size:   ");
        TrText.setEnabled(false);
        TcText.setEnabled(false);
        int tR = Integer.parseInt(TrText.getText());
        int tC = Integer.parseInt(TcText.getText());
        int dR = Integer.parseInt(DrText.getText());
        int dC = Integer.parseInt(DcText.getText());
        int Size = 0;
        for (int i=0;i<Integer.parseInt(SizeText.getText());i++)
            Size ++;
        tr = tR;
        tc = tC;
        dr = dR;
        dc = dC;
        size = Size;
        southPanel.add(CancelButton);//添加各组件到窗体
        southPanel.add(TrLabel);
        southPanel.add(TrText);
        southPanel.add(TcLabel);
        southPanel.add(TcText);
        southPanel.add(DrLabel);
        southPanel.add(DrText);
        southPanel.add(DcLabel);
        southPanel.add(DcText);
        southPanel.add(SizeLabel);
        southPanel.add(SizeText);
        southPanel.add(OKButton);

        getContentPane().add(southPanel, BorderLayout.NORTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    class gridLayout {
        public gridLayout() {
            centerPanel.setLayout(new GridLayout(0, size));
            button = new JButton[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    button[i][j] = new JButton();
                    if (i == dr && j == dc) {
                        button[i][j].setBackground(Color.BLUE);
                        button[i][j].setText("<html><font size='3' color='white'>覆盖</font></html>");
                        button[i][j].setEnabled(false);
                    }
                    centerPanel.add(button[i][j]);
                }
            }
        }
        private void sleep1()
        {
            try{  
                Thread.sleep(100);  
            }catch (InterruptedException e){
                return;
            } 
        }
        public void ChessBoard(int tr, int tc, int dr, int dc, int size) {//算法实现
            if (size == 1) // 棋盘方格大小为1,说明递归到最里层
                return;
            int t = tile++;// 每次递增1
            Random rd =  new Random();
            red=rd.nextFloat();
            green=rd.nextFloat();
            blue=rd.nextFloat();
            Color col = new Color(red,green,blue);
            int s = size / 2; // 棋盘中间的行、列号(相等的)
            // 检查特殊方块是否在左上角子棋盘中
            if (dr < tr + s && dc < tc + s) // 在
                ChessBoard(tr, tc, dr, dc, s);
            else // 不在，将该子棋盘右下角的方块视为特殊方块
            {
                button[tr + s - 1][tc + s - 1].setBackground(col);
                button[tr + s - 1][tc + s - 1].setEnabled(false);
                button[tr + s - 1][tc + s - 1].setText("<html><Font size='4',color='white'>"+t+"</Font></html>");
                ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
            }
            // 检查特殊方块是否在右上角子棋盘中
            if (dr < tr + s && dc >= tc + s) // 在
                ChessBoard(tr, tc + s, dr, dc, s);
            else // 不在，将该子棋盘左下角的方块视为特殊方块
            {
                button[tr + s - 1][tc + s].setBackground(col);
                button[tr + s - 1][tc + s].setEnabled(false);
                button[tr + s - 1][tc + s ].setText("<html><Font size='4',color='white'>"+t+"</Font></html>");
                ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
            }
            // 检查特殊方块是否在左下角子棋盘中
            if (dr >= tr + s && dc < tc + s) // 在
                ChessBoard(tr + s, tc, dr, dc, s);
            else // 不在，将该子棋盘右上角的方块视为特殊方块
            {
                button[tr + s][tc + s - 1].setBackground(col);
                button[tr + s][tc + s - 1].setEnabled(false);
                button[tr + s ][tc + s - 1].setText("<html><Font size='4',color='white'>"+t+"</Font></html>");
                ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
            }
            // 检查特殊方块是否在右下角子棋盘中
            if (dr >= tr + s && dc >= tc + s) // 在
                ChessBoard(tr + s, tc + s, dr, dc, s);
            else // 不在，将该子棋盘左上角的方块视为特殊方块
            {
                button[tr + s][tc + s].setBackground(col);
                button[tr + s][tc + s].setEnabled(false);
                button[tr + s ][tc + s ].setText("<html><Font size='4',color='white'>"+t+"</Font></html>");
                ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
            }
        }
    }
    public class OKButtonAction implements ActionListener {//点下一个按钮时的事件响应
        public void actionPerformed(ActionEvent e) {
            // TODO Auto-generated method stub
            JButton whichButton = (JButton) e.getSource();//获取点击的事件，即是点下了哪个按钮
            String whichName = whichButton.getActionCommand();
            if(whichName.equals("确定或开始")) {
                getContentPane().add(centerPanel, BorderLayout.CENTER);
                int tR = Integer.parseInt(TrText.getText());
                int tC = Integer.parseInt(TcText.getText());
                int dR = Integer.parseInt(DrText.getText());
                int dC = Integer.parseInt(DcText.getText());
                int Size = 0;
                for (int i=0;i<Integer.parseInt(SizeText.getText());i++)
                    Size++;
                tr = tR;
                tc = tC;
                dr = dR;
                dc = dC;
                size = Size;
                try {
                    gridLayout grid = new gridLayout();
                    grid.ChessBoard(tr, tc, dr, dc, size);
                    centerPanel.updateUI();
                } catch (Exception EX) {
                    EX.printStackTrace();
                }
                panel.removeAll();
                OKButton.setEnabled(false);
            }
            if (whichName.equals("取消或清除")) {//当你点下一个提示按钮时的事件响应
                JLabel label = new JLabel();
                label.setHorizontalAlignment(JLabel.CENTER);
                label.setText("<html><Font size='+8',color='red'><center><b><br>    您取消了操作或是   <br><Font size='+8',color='blue'><center>您清除了前一个棋盘……" +
                        "<br><Font size='+8',color='green'><center>下面是关于题目的介绍<br><br><br><br><br><br>  </b></Font></html>");
                //    JLabel l = new JLabel("题目要求");
                JTextArea area = new JTextArea("在一个2k x 2k ( 即：2^k x 2^k )个方格组成的棋盘中，恰有一个方格与其他方格不同，" +
                        "称该方格为一特殊方格，且称该棋盘为一特殊棋盘。在棋盘覆盖问题中，要用4种不同形态的L型骨牌覆盖给定的特殊棋盘上除特殊方格以外的所有方格，" +
                        "且任何2个L型骨牌不得重叠覆盖。",7,60);
                area.setLineWrap(true);
                area.setBackground(Color.blue);
                area.setForeground(Color.white);
                area.setFont (new Font("SansSerif", Font.PLAIN, 14));
                area.setEditable(false);
                //    FlowLayout layout =  new FlowLayout();
                //    layout.addLayoutComponent(arg0, arg1)
                panel.add(label,centerPanel );
                //    panel.add(l,southPanel);

                panel.add(area,southPanel);
                getContentPane().add(panel, BorderLayout.CENTER);
                panel.updateUI();
                tile=1;
                centerPanel.removeAll();
                OKButton.setEnabled(true);
            }
        }
    }
    public static void main(String[] args) {//主函数方法实现
        chessBoard chess = new chessBoard();
        chess.setVisible(true);
        Runtime run = Runtime.getRuntime();
        run.gc();//手动清除数据垃圾
    }
}
