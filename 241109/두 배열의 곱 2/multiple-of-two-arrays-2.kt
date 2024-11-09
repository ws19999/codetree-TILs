fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    var arr1=Array(4){IntArray(2) }
    for(i in 0..3)
    {
        var temp=br.readLine().trim().split(" ").map{it.toInt()}.toIntArray()
        arr1[i]=temp
    }
    br.readLine()
    var arr2=Array(4){IntArray(2) }
    for(i in 0..3)
    {
        var temp=br.readLine().trim().split(" ").map{it.toInt()}.toIntArray()
        arr2[i]=temp
    }
    for(i in 0..3)
    {
        for(j in 0..1)bw.write("${arr1[i][j]*arr2[i][j]} ")
        bw.write("\n")
    }
    bw.close()
}