fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    var str:Array<String> = Array(5){""}
    for(i in 0..4)str[i]=br.readLine()
    for(i in 0..14)
    {
        for(j in 0..4)
        {
            if(str[j].length>i)bw.write("${str[j][i]}")
        }
    }
    bw.close()
}