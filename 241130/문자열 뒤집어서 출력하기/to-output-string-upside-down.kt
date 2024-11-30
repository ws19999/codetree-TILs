fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    var arr:MutableList<String> = mutableListOf()
    for(i in 1..4)arr.add(br.readLine())
    for(i in 3 downTo 0)
    {
        val len=arr[i].length
        for(j in len-1 downTo 0)bw.write("${arr[i][j]}")
        bw.write("\n")
    }
    bw.close()
}