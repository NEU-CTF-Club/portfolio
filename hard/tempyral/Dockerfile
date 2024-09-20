FROM python:3.9-slim

RUN apt-get update && apt-get install -y socat && apt-get clean

WORKDIR /app

COPY tempyral.py .

RUN chmod +x tempyral.py

EXPOSE 1234

CMD socat TCP-LISTEN:1234,reuseaddr,fork EXEC:"python3 /app/tempyral.py",pty,stderr
