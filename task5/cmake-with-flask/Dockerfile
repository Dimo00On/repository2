FROM python:3.6

RUN mkdir -p /opt/techprog
WORKDIR /opt/techprog
COPY . /opt/techprog

RUN apt-get update && \
    apt-get install -y gcc g++ cmake && \
    pip install Flask && \
    mkdir -p /opt/techprog/build && cd build && cmake .. && make && \
    useradd tp2022user
USER tp2022user

EXPOSE 8898
CMD ["python3", "app.py", "--host", "0.0.0.0", "--port", "8898"]
