import React, { useState, useEffect } from "react";
import "./App.css";
import { Button, Col, Container, Row } from "react-bootstrap";
import axios from "axios";

function App(): JSX.Element {
    const [message, setMessage] = useState("");

    useEffect(() => {
        const fetchData = async () => {
            try {
                const response = await axios.get("http://localhost:8080/api");

                const { message } = response.data;

                setMessage(message);
            } catch (error) {
                console.error("Error fetching data:", error);
            }
        };

        fetchData();

    }, []);

    return (
        <div className="App">
            <h1>this is header text</h1>
            <header className="App-header">
                {message ? message : "Loading..."}
            </header>
            <p>
                Edit <code>src/App.tsx</code> and save. This page will
                automatically reload. Also im Alex Hoy, Hello World.
            </p>
            <Container>
                <Row>
                    <Col>
                        <div
                            style={{
                                height: "40px",
                                width: "30px",
                                backgroundColor: "red"
                            }}
                        ></div>
                    </Col>
                    <Col>
                        Why this bird is angry:
                        <ol>
                            <li>Eggs got taken</li>
                            <li>He is red</li>
                            <li>He is frowning</li>
                        </ol>
                        <div
                            style={{
                                height: "30px",
                                width: "40px",
                                backgroundColor: "red"
                            }}
                        ></div>
                    </Col>
                </Row>
            </Container>
            <Button onClick={() => console.log("Hello World!")}>
                Log Hello World
            </Button>
        </div>
    );
}

export default App;