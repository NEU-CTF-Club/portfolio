FROM ubuntu:latest

# Install some libs
RUN apt-get update && apt-get -y install xinetd
RUN apt-get -y install python3

# create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

# add chall items
COPY flag.txt /home/ctf/flag.txt
COPY jail.py /home/ctf/jail.py
COPY xinetd /etc/xinetd.d/xinetd

# set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/jail.py
RUN chmod 440 /home/ctf/flag.txt
RUN chmod 644 /etc/xinetd.d/xinetd
RUN chown root:root /etc/xinetd.d/xinetd

USER ctf
WORKDIR /home/ctf
EXPOSE 8412

CMD ["/usr/sbin/xinetd", "-dontfork"]
