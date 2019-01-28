package socket;

import java.net.Socket;
import java.io.*;

public class Client {
    private Integer port;
    private String host;
    private Socket server;
    
    private BufferedReader bufferReader;
    private BufferedWriter bufferWriter;
    
    public Client(String host, Integer port) throws Exception{
        this.port = port;
        this.host = host;
        
        this.server = new Socket(host, port);
        
        InputStream inStr = this.server.getInputStream();
        InputStreamReader inStrRead = new InputStreamReader(inStr);
        bufferReader = new BufferedReader(inStrRead);
        
        OutputStream outStre = this.server.getOutputStream();
        OutputStreamWriter outStrWrite = new OutputStreamWriter(outStre);
        bufferWriter = new BufferedWriter(outStrWrite);   
    }
    
    public String recv() throws Exception{
        String message = bufferReader.readLine();
        return message;
    }
    public void send(String message) throws Exception{
        bufferWriter.write(message+"\n");
        bufferWriter.flush();
        
    }
    
}
