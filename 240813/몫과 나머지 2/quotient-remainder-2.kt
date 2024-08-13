fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val (x,y)=br.readLine().split(" ").map{it.toInt()}
    bw.write("${x/y}---${x%y}")
    bw.close()
    br.close()
}