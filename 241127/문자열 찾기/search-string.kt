fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val str=br.readLine()
    val len=str.length
    var KOI=0
    var IOI=0
    for(i in 0..len-3)
    {
        if(str[i+1]=='O' && str[i+2]=='I')
        {
            if(str[i]=='K')KOI++
            if(str[i]=='I')IOI++
        }
    }
    bw.write("$KOI $IOI")
    bw.close()
}