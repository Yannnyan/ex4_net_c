
[ex4_net](https://github.com/11sdz/ex4_net_c/)
# ex4_net_c
### Table of contents
[Google Docs](https://docs.google.com/document/d/1RXLC6avHmxrM6UJ2W5WMFCVqxP4nxs6NfjOwUP5whTo/edit)




sudo apt install iproute

לאחר מכן נייצר איבוד פאקטות ראנדומאלי:

sudo tc qdisc add dev lo root netem loss 10%

אנו נרצה לשנות את אחוז איבוד הפאקטות בכל סיבוב דגימות:

sudo tc qdisc change dev lo root netem loss XX%

כאשר נרצה למדוד 10,15,20,25,30 אחוזי איבוד.
