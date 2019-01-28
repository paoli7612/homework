package socket;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class Server{
    private Integer port;
    private Socket client;
    private ServerSocket sock;
    
    private BufferedReader bufferReader;
    private BufferedWriter bufferWriter;
    
    
    public Server(Integer port) throws Exception{
        this.port = port;
        sock = new ServerSocket(port);
        client = server.accept();
        
        InputStream inStr = client.getInputStream();
        InputStreamReader inStrRead = new InputStreamReader(inStr);
        bufferReader = new BufferedReader(inStrRead);
        
        OutputStream outStre = client.getOutputStream();
        OutputStreamWriter outStrWrite = new OutputStreamWriter(outStre);
        bufferWriter = new BufferedWriter(outStrWrite);
    }       
    
    public Integer get_port(){
        return this.port;
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
