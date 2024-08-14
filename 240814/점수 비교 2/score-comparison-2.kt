data class person(var science:Int=0,var society:Int=0)
fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    var (sc,so)=br.readLine().split(" ").map{it.toInt()}
    var A=person(sc,so)
    var (s1,s2)=br.readLine().split(" ").map{it.toInt()}
    var B=person(s1,s2)
    if(A.science>B.science && A.society>B.society)bw.write("1")
    else bw.write("0")
    bw.close()
}