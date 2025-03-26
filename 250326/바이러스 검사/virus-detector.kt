fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val N=br.readLine().toInt()
    var ans=N.toLong()
    val guests=br.readLine().trim().split(" ").map{it.toInt()}.toIntArray()
    val (a,b)=br.readLine().trim().split(" ").map{it.toInt()}
    for(i in 0..N-1){
        guests[i]-=a
        if(guests[i]>0){
            ans+=guests[i]/b
            if(guests[i]%b>0)ans++
        }
    }
    bw.write("$ans")
    bw.close()
}