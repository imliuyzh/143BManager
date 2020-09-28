# 143BManager
This project develops a simple process and resource manager. The manager provides the basic operations invoked by processes to create and destroy processes, and to request and release resources. A manually invoked timeout function mimics the behavior of preemptive scheduling. 

## Background
### Process
A process can be in one of three states: ready, running, blocked. It typically cycles through the states many times throughout its lifetime:
<img src="https://i.ibb.co/3MX25Vf/ch1img1v2.png" />
