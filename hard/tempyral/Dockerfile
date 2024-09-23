FROM python:3.12-slim

RUN apt-get update && apt-get install -y socat && apt-get clean

WORKDIR /app

COPY tempyral.py .

RUN chmod +x tempyral.py

EXPOSE 1100

CMD socat TCP-LISTEN:1100,reuseaddr,fork EXEC:"python3 /app/tempyral.py",pty,stderr
