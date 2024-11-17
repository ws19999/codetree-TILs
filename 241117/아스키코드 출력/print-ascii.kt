fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val n=br.readLine().toInt()
    for(i in 1..n)
    {
        val num=br.readLine().toInt()
        bw.write("${num.toChar()}\n")
    }
    bw.close()
}