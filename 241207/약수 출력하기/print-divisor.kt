import kotlin.math.sqrt

fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val N=br.readLine().toInt()
    var arr:MutableList<Int> = mutableListOf()
    for(i in 1..sqrt(N.toDouble()).toInt())
    {
        if(N%i==0) {
            bw.write("${i} ")
            if(i!=N/i)arr.addFirst(N/i)
        }

    }
    for(i in arr)bw.write("${i} ")
    bw.close()
}