fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val (a,b)=br.readLine().split(" ")
    bw.write("${b.substring(0,3)+a}")
    bw.close()
}