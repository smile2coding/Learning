# Modbus RTU time sequence

In modbus protocol, there are 1.5T and 3.5T time sequence required.

## 3.5T (3.5 char time)

> Modbus RTU frame is separated by 3.5 char time. When detecting 3.5t interval, it records one frame.

![modbus 3.5T](img/modbus%20RTU%203.5T.drawio.png)

```mermaid
sequenceDiagram
    participant Alice
    participant Bob
    Alice->>John: Hello John, how are you?
    loop Healthcheck
        John->>John: Fight against hypochondria
    end
    Note right of John: Rational thoughts <br/>prevail!
    John-->>Alice: Great!
    John->>Bob: How about you?
    Bob-->>John: Jolly good!

```


```mermaid
gitGraph
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       commit
       branch develop
       commit
       commit
       commit
       checkout main
       commit
       commit
       commit
       commit
       commit
       commit
       branch test
       branch dev
       commit
       commit
       commit
       commit
       commit
```