fun main()
{
    val weight=147
    val rate=0.165
    val r=String.format("%.5f",rate)
    val ans=String.format("%.5f",weight*rate)
    println("$weight * $r = $ans")
}